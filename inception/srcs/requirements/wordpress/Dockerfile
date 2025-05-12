FROM debian:buster

# Mise à jour des paquets et installation des dépendances
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y wget php7.3 php-fpm php-mysql mariadb-client

# Téléchargement et extraction de WordPress
RUN wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www/ && \
    cd /var/www/ && \
    tar -xvf wordpress-6.0.tar.gz && \
    rm wordpress-6.0.tar.gz && \
    chown -R root:root /var/www/wordpress

# Installation de WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Création du dossier de configuration
RUN mkdir -p /conf && chmod 755 /conf

# Fichiers de configuration PHP et setup
COPY conf/php.conf /etc/php/7.3/fpm/pool.d/www.conf
#COPY ../../../.env /conf/.env
COPY conf/setup.sh /conf/setup.sh
RUN chmod +x /conf/setup.sh

# Point d’entrée
ENTRYPOINT ["/bin/bash", "/conf/setup.sh"]

# Exposition du port pour PHP-FPM
EXPOSE 9000
