# wywołanie ./find_tar.sh ."rozszerzenie" -"ilość dni" "nazwa".tar
# flagi tar:
# -r  włącza bezwarunkowe dołączanie plików do archiwum
# -f  określa nazwę pliku archiwum tar
# -v  wypisuje nazwy wszystkich plików

find -iname "*.$1" -ctime -$2 -exec tar -rvf $3 {} \;
