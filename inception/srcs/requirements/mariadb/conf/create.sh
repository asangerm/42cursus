#!/bin/bash

set -a
source /path/to/.env
set +a


service mysql start

# On attend un peu que le service soit réellement prêt (optionnel mais recommandé)
sleep 5

# Exécuter les commandes avec mot de passe root si défini
mysql -u root <<-EOSQL
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOSQL

# Arrêter le service proprement
mysqladmin -u root -p"${SQL_ROOT_PASSWORD}" shutdown

# Relancer MySQL en mode safe
exec mysqld_safe
