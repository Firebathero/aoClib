.PHONY: all clean rebuild debug help valgrind perf

BUILD_DIR := build
BIN_DIR := bin

all: $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

$(BUILD_DIR):
	cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	rm -rf valgrind_output perf_output

rebuild: clean all

debug:
	cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_DIR)

valgrind:
	@if [ -z "$(DAY)" ]; then \
		echo "Usage: make valgrind DAY=<day_number>"; \
		exit 1; \
	fi
	./util/run_valgrind.sh $(DAY)

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all (default) - Build the project"
	@echo "  clean         - Remove build artifacts"
	@echo "  rebuild       - Clean and rebuild"
	@echo "  debug         - Build with debug symbols"
	@echo "  valgrind      - Run Valgrind (use: make valgrind DAY=<number>)"
	@echo "  perf          - Run perf (use: make perf DAY=<number>)"
	@echo "  help          - Show this help message"