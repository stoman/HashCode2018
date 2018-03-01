#!/bin/sh
while true
do
	git checkout master
	git pull
	for commit in $(git rev-list master)
	do
		dir="commit-$commit"
		if [ ! -d $dir ]
		then
			echo "running build $commit"
			mkdir $dir
			git checkout $commit
			cp -r data $dir
			cp -r code $dir
			cp -r grader $dir
			cp -r visualize $dir
			cp Makefile $dir
			cp README.md $dir
			cp LICENCE $dir
			git checkout master
			(cd $dir && make clean && make build && make -j4 data && make grades.html) &
		fi
	done
	sleep 10
done
