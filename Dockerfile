FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY docker .

RUN cmake -B build && cmake --build build

CMD ["./build/exalgo"]