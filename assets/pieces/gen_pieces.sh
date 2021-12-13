#!/bin/bash
for file in ../png/*.png; do
  filename="${file%.*}"
  convert "../png/${filename}.png" -background "#008080" -alpha remove -alpha off "${filename}_bg_b.png"
  convert "../png/${filename}.png" -background "#d5efff" -alpha remove -alpha off "${filename}_bg_w.png"
done