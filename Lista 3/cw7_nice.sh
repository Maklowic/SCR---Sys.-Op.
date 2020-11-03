#!/bin/bash

# nice obniza priorytet procesu.
# wykorzystalem go do obnizenia priorytetu jednego z dwoch skryptow
# bez uzycia "nice" komenda "./skrypt0.sh & ./skrypt1.sh &" powodowała,
# że jako pierwszy wywoałał się skrypt 0 a potem 1.
# Zdjęcie(zdj_1_bez_nice) terminala znajduje się w repozytorium.

# Sprawdzic wartosc nice można przez wywołanie "ps -lx" w wyswietlonej tresci 
# 6. kolumna od lewej to wartość nice (nazwa kolumny "NI").

# wykorzystujac nice obnize priorytet skryptu 0, żeby wykonal sie jako drugi
# sktypt "cw7_nice.sh" wykonuje obnizenie przez zmiane liczny nice skrypt0.sh na 10.
# Wynik to drugie zdjecie (zdj_2_z_nice) w repozytorium.

# renice służy do zmieny priorytetu działającego/ych procesu/ów na wartość wywołaną.
# wywołanie: renice -n 8 -u 1000
# zmiana o 8
# -u - zmienia priorytet wszystkich procesów użytkownika o danym UID (moje UID 1000)
# -p - procesowi o dnaym PID
# -g - grupie
# prezentacja na zdjeciu 3 (zdj_3_renice)

# ---=== ZAWARTOSC skrypt0.sh ===---
# echo Jestem skrypt 000000
# sleep 10;
# ---=== ZAWARTOSC skrypt1.sh ===---
# echo Jestem skrypt 111111
# sleep 10;

nice -n 10 ./skrypt0.sh & ./skrypt1.sh &

