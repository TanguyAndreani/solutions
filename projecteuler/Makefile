ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

all: run_tests

.PHONY: run_tests
run_tests:
	GOPATH=${ROOT_DIR} go test $(shell ls src)

.PHONY: fmt
fmt:
	GOPATH=${ROOT_DIR} go fmt $(shell ls src)
