lokalizacja=$(pwd)

for mail in $(cat $lokalizacja/adresy.txt)
do
    cat $lokalizacja/tresc.txt | mutt -s "Zapytanie ofertowe" $mail -a $lokalizacja/spec*.pdf
done
