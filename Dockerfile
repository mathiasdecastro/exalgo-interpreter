FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -B build && cmake --build build

ENTRYPOINT ["./build/exalgo"]