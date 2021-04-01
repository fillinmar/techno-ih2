BUILD_DIR?=build
# BUILD PROJECT :
build-project:
	mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && make
# TEST RUNNING :
run-check-time-parallel-test:
	cd $(BUILD_DIR)/tests/time_check/parallel_time \
		&& ./time_check_parallel_test
run-check-time-static-test:
	cd $(BUILD_DIR)/tests/time_check/static_time \
		&& ./time_check_static_test
run-all-time-test:
	 make run-check-time-parallel-test \
                                  && make run-check-time-static-test
run-matrix-parallel-test:
	cd $(BUILD_DIR)/tests/unit/matrix/parallel_matrix \
		&& ./parallel_matrix_test_correct

run-matrix-static-test:
	cd $(BUILD_DIR)/tests/unit/matrix/static_matrix \
		&& ./static_matrix_test_correct

run-all-tests:
	 make run-matrix-parallel-test \
                                  && make run-matrix-static-test \

# VALGRIND RUNNING :
run-valgrind-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose $(dir)

run-valgrind-test-time-static:
	make run-valgrind-check dir=./$(BUILD_DIR)/tests/unit/check_time/static/static_matrix_test

run-valgrind-test-matrix-dynamic:
	cd $(BUILD_DIR)/tests/unit/matrix/parallel_matrix \
		make run-valgrind-check dir=./parallel_matrix_test_correct

run-valgrind-test-matrix-static:
	cd $(BUILD_DIR)/tests/unit/matrix/static_matrix \
		make run-valgrind-check dir = ./static_matrix_test_correct

run-valgrind-test-dynamic:
	make run-valgrind-check dir=./$(BUILD_DIR)/tests/unit/check_time/dynamic/dynamic_matrix_test

run-all-vg-check:
	make run-valgrind-test-time-static \
			&& make run-valgrind-test-matrix-dynamic \
				&& make run-valgrind-test-matrix-static \
					&& make run-valgrind-test-dynamic

# CODE COVERAGE :
get-gcov:
	mkdir $(output) && cd $(output) && gcov $(file) && cp -rf $(path) .

get-gcov-static-matrix:
	make get-gcov output=gcov/static_matrix file=../../build/src/static_matrix/CMakeFiles/static_matrix.dir/matrix.c.gcno path=../../build/src/static_matrix/CMakeFiles/static_matrix.dir/.

get-gcov-parallel-matrix:
	make get-gcov output=gcov/dynamic_matrix file=../../build/src/parallel_matrix/CMakeFiles/parallel_matrix.dir/matrix.c.gcno path=../../build/src/parallel_matrix/CMakeFiles/parallel_matrix.dir/.

get-gcov-all:
	mkdir gcov && make get-gcov-static-matrix && make get-gcov-parallel-matrix

get-lcov:
	lcov --capture --directory $(directory) --output-file $(output_filename).info

get-lcov-static-matrix:
	mkdir coverage/static_matrix && make get-lcov directory=gcov/static_matrix output_filename=coverage/static_matrix/static_matrix

get-lcov-dynamic-matrix:
	mkdir coverage/parallel_matrix && make get-lcov directory=gcov/parallel_matrix output_filename=coverage/parallel_matrix/parallel_matrix

get-lcov-all:
	mkdir coverage && make get-lcov-parallel-matrix && make get-lcov-static-matrix

generate-html:
	cd $(dir) && genhtml $(file).info  --output-directory .

generate-html-parallel-matrix:
	make generate-html dir=coverage/parallel_matrix file=parallel_matrix

generate-html-static-matrix:
	make generate-html dir=coverage/static_matrix file=static_matrix

generate-html-all:
	make generate-html-parallel-matrix && make generate-html-static-matrix

get-all-coverage:
	make get-gcov-all && make get-lcov-all && make generate-html-all
