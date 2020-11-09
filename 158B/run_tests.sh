#!/usr/bin/env bash

passed_tests=true

for i in {1..3}
do
  < "./tests/in/$i.txt" ./main > "./tests/out/$i.txt"
  if ! cmp --silent ./tests/expected/$i.txt ./tests/out/$i.txt; then
    passed_tests=false
    echo "Error at test number $i! (Different outputs)"
    echo "Expected:"
    cat ./tests/expected/$i.txt
    echo "---------"
    echo "Actual:"
    cat ./tests/out/$i.txt
  fi
done

if [ "$passed_tests" == true ]; then
  echo "All tests passed!"
fi