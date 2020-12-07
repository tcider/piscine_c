cat $1 | grep -i -E "(nicolas.bauer)|(bauer.nicolas)" phonebook | grep -o -E "([[:digit:]]|[()-]){10,13}"
