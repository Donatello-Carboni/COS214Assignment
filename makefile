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

# Clean generated files
clean:
	rm -rf ./build/*