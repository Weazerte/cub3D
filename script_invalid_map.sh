#!/bin/bash

# Chemin vers le répertoire contenant les fichiers de carte invalides
invalid_map_dir="map/invalid_map"

# Vérifie si le répertoire des cartes invalides existe
if [ ! -d "$invalid_map_dir" ]; then
    echo "Le répertoire des cartes invalides n'existe pas."
    exit 1
fi

# Récupère la liste des fichiers de carte invalides dans le répertoire
map_files=$(find "$invalid_map_dir" -type f)

# Parcours chaque fichier de carte et exécute valgrind
for map_file in $map_files; do
    echo "Exécution de valgrind sur $map_file"
    valgrind "./cub3D" "$map_file"
    echo "------------------------------"
done
