#!/bin/bash
valgrind --suppressions=MacroLibX/valgrind.supp --leak-check=full ./solong $1
