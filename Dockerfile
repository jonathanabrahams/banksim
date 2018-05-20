ARG ALPINE_VERSION=3.7
FROM alpine:${ALPINE_VERSION} as builder
WORKDIR /src/
RUN apk update && apk add --virtual build-env \
build-base \
gcc \
cmake \
boost-dev;
COPY . /src
RUN cmake . ; \
make ; \
cmake test/CMakeLists.txt ; \
make -C ./test

FROM alpine:3.7
WORKDIR /src/
RUN apk add --no-cache libgcc libstdc++
COPY --from=builder /src/bin/main /src/test/runTests /src/
