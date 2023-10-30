make:
	cd build && make
	cd ../

run:
	cd build && make
	cd ../
	./bin/main

test:
	cd build && make
	cd ../
	./bin/test
  
clean:
	rm -rf ./build/*