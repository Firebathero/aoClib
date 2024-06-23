#!/bin/bash

is_wsl() {
    if [ -f /proc/version ]; then
        if grep -qi microsoft /proc/version; then
            return 0
        fi
    fi
    return 1
}

install_common_tools() {
    sudo apt update
    sudo apt install -y linux-tools-generic
    sudo apt install -y valgrind kcachegrind
}

echo "Valgrind version:"
valgrind --version

echo "Setup complete. Please restart your shell or run 'source ~/.bashrc' to update your PATH."