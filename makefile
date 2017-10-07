CPP=g++
CPPFLAGS=--std=c++14

test:
	read -p "Username: " USERNAME; \
	mkdir "test/$$USERNAME" -p; \
	cp solutions/$$USERNAME/*.hpp test/$$USERNAME/; \
	cp contigsum_test.cpp test/$$USERNAME/; \
	cp inversions_test.cpp test/$$USERNAME/; \
	$(CPP) $(CPPFLAGS) test/$$USERNAME/contigsum_test.cpp -o test/$$USERNAME/build; \
	test/$$USERNAME/build; \
	$(CPP) $(CPPFLAGS) test/$$USERNAME/inversions_test.cpp -o test/$$USERNAME/build; \
	test/$$USERNAME/build;

clean:
	rm -Rf test