test_unitaire () {
	echo $1 >> time_file
	time ./fillit "map/"/$1 2> tmp 1> /dev/null
	cut -d' ' -f1 tmp > tmp2
	echo -n "\ttime: " >> time_file
	grep -m 1 '.' tmp2 >> time_file
}
make
rm time_file



test_unitaire "valid_sample.txt"



cat time_file
rm -rf tmp tmp2
