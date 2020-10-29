#!/bin/bash

trap 'echo "Jestem odporny na SIGHUP"' HUP
trap 'echo "Jestem odporny na SIGINT"' INT
trap 'echo "Jestem odporny na SIGQUIT"' QUIT
trap 'echo "Jestem odporny na SIGFPE"' FPE
trap 'echo "Jestem odporny na SIGILL"' ILL
trap 'echo "Jestem odporny na SIGTRAP"' TRAP
trap 'echo "Jestem odporny na SIGIOT"' ABRT
trap 'echo "Jestem odporny na SIGBUS"' BUS
trap 'echo "NIE jestem odporny na SIGKILL"' KILL
trap 'echo "Jestem odporny na SIGUSR1"' USR1
trap 'echo "Jestem odporny na SIGSEGV"' SEGV
trap 'echo "Jestem odporny na SIGUSR2"' USR2
trap 'echo "Jestem odporny na SIGPIPE"' PIPE
trap 'echo "Jestem odporny na SIGALRM"' ALRM
trap 'echo "Jestem odporny na SIGTERM"' TERM


while true; do
    date
    sleep 1
done
