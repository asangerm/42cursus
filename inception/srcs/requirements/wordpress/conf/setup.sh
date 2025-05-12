#!/bin/bash

# Charger les variables d'environnement (elles sont passées depuis docker-compose)
set -a
source /conf/.env
set +a

# Attendre que la base de données MariaDB soit prête
until mysqladmin ping -h mariadb --silent; do
  echo "Waiting for MariaDB..."
  sleep 2
done

# Vérifier si WordPress est déjà installé
if ! wp core is-installed --allow-root --path='/var/www/wordpress'; then
    echo "Installing WordPress..."

    wp config create \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost=mariadb:3306 \
        --allow-root \
        --path='/var/www/wordpress'

    wp core install \
        --url=https://$DOMAIN_NAME \
        --title="$SITE_TITLE" \
        --admin_user=$SITE_ADMIN_USER \
        --admin_password=$SITE_ADMIN_PASSWORD \
        --admin_email=$SITE_ADMIN_EMAIL \
        --allow-root \
        --path='/var/www/wordpress'

    echo "Creating user: $SITE_USER1_LOGIN"

    wp user create \
        $SITE_USER1_LOGIN $SITE_USER1_MAIL \
        --user_pass=$SITE_USER1_PASSWORD \
        --role=author \
        --allow-root \
        --path='/var/www/wordpress'
fi

# S'assurer que /run/php existe
mkdir -p /run/php

# Lancer PHP-FPM
exec php-fpm7.3 -F
