#!/bin/bash

cppcheck --enable=all --quiet --file-filter=*.c --file-filter=*.cc --output-file=cppcheck_ret.txt --template="{file}:{line}:{column} [{severity}] [id] {message}\n{code}" `pwd`
