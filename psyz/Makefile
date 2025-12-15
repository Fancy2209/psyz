BUILD_DIR := build
TEST_DIR := tests/build

.PHONY: build clean format test

build: $(BUILD_DIR)/libpsyz.a

$(BUILD_DIR)/libpsyz.a: CMakeLists.txt
	cmake -GNinja -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TEST_DIR)

format:
	find src psxgen tests -type f -name '*.c' -exec clang-format -i {} +

test:
	@mkdir -p $(TEST_DIR)
	cmake -DCMAKE_BUILD_TYPE=Debug -GNinja -S tests/ -B $(TEST_DIR)
	cmake --build $(TEST_DIR)
	cd $(TEST_DIR) && ./psyz_tests
