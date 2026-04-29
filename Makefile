clean:
	cargo clean

build:
	cargo build

check:
	cargo check

run:
	cargo run

test:
	cargo test

clippy:
	cargo clippy --all-targets --all-features -- -D warnings

format:
	cargo fmt --all -- --check