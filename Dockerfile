FROM gcc:9.3.0

WORKDIR /usr/src/app

RUN apt install libgmp-dev
COPY bellnums.cpp .
RUN g++ bellnums.cpp -lgmp -lgmpxx -o bellnums

ENTRYPOINT [ "./bellnums" ]
