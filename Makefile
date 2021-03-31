BUILD_DIR?=build
# BUILD PROJECT :
build-project:
	mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && make
