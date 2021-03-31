BUILD_DIR?=build
# BUILD PROJECT :
build-project:
	mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && make
# TEST RUNNING :
run-time-static-test:
	./$(BUILD_DIR)/tests/unit/check_time/static/static_matrix_test

run-time-dynamic-test:
	./$(BUILD_DIR)/tests/unit/check_time/dynamic/dynamic_matrix_test

run-matrix-dynamic-test:
	cd $(BUILD_DIR)/tests/unit/matrix/dynamic_matrix \
		&& ./dynamic_matrix_test_correct

run-matrix-static-test:
	cd $(BUILD_DIR)/tests/unit/matrix/static_matrix \
		&& ./static_matrix_test_correct

run-all-tests:
	make run-time-dynamic-test \
			&& make run-time-static-test \
                        && make run-matrix-dynamic-test \
                                  && make run-matrix-static-test

# VALGRIND RUNNING :
run-valgrind-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose $(dir)

run-valgrind-test-date-check:
	make run-valgrind-check dir=./$(BUILD_DIR)/tests/unit/date/date_test

run-valgrind-test-blog-check:
	make run-valgrind-check dir=./$(BUILD_DIR)/tests/unit/blog/blog_test

run-all-vg-check:
	make run-valgrind-test-date-check \
			&& make run-valgrind-test-blog-check

# CODE COVERAGE :
get-gcov:
	mkdir $(output) && cd $(output) && gcov $(file) && cp -rf $(path) .

get-gcov-date:
	make get-gcov output=gcov/date file=../../build/src/date/CMakeFiles/date.dir/date.c.gcno path=../../build/src/date/CMakeFiles/date.dir/.

get-gcov-blog:
	make get-gcov output=gcov/blog file=../../build/src/blog/CMakeFiles/blog.dir/blog.c.gcno path=../../build/src/blog/CMakeFiles/blog.dir/.

get-gcov-all:
	mkdir gcov && make get-gcov-date && make get-gcov-blog

get-lcov:
	lcov --capture --directory $(directory) --output-file $(output_filename).info

get-lcov-date:
	mkdir coverage/date && make get-lcov directory=gcov/date output_filename=coverage/date/date

get-lcov-blog:
	mkdir coverage/blog && make get-lcov directory=gcov/blog output_filename=coverage/blog/blog

get-lcov-all:
	mkdir coverage && make get-lcov-date && make get-lcov-blog

generate-html:
	cd $(dir) && genhtml $(file).info  --output-directory .

generate-html-blog:
	make generate-html dir=coverage/blog file=blog

generate-html-date:
	make generate-html dir=coverage/date file=date

generate-html-all:
	make generate-html-date && make generate-html-blog

get-all-coverage:
	make get-gcov-all && make get-lcov-all && make generate-html-all
