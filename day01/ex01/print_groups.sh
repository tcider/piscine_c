#!/bin/sh
groups $USER | tr " " "," | tr -d "\n"
