#!/bin/bash

# Zmniejszono limit użytkownika do 60 procesów za pomocą komendy"
#           ulimit -u 60
# Jest to ponad 3 - krotnie mniej (zdj_4_ulimit).

# Skrypt poniżej to "fork bomba" skrypt, który wywołuje sam siebie. 
# Po wywołaniu skopiuje się tyle razy na ile pozwoli limit procesów.
# W pewnym momencie fork już nie chce sie wykonywac

# Zabicie wszystkich procesów jest możliwe:
# -- zabicie pierwszego procesu (jest ich bardzo dużo),
# -- zabicie terminala (basha) który wywołał fork bombe,
# -- uzycie killall -u user_name, co zabija wszystkie procesy użytkownika.

fork_bomb()
{
	fork_bomb | fork_bomb&
};
fork_bomb