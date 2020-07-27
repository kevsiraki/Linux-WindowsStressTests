#!/bin/bash
echo Quad Core CPU Stress Test
for i in 1 2 3 4; do while : ; do : ; done & done
echo Enter anything to stop.
read var
killall cpustress.sh