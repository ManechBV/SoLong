#!/bin/bash
valgrind --leak-check=full	--show-leak-kinds=all --suppressions=MacroLibX/valgrind.supp ./solong $1
