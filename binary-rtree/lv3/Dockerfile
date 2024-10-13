FROM ubuntu:20.04

COPY rtree /rtree
RUN chmod +x /rtree

COPY libc-2.31.so /libc-2.31.so
COPY ld-2.31.so /ld-2.31.so

RUN chmod u=rwx,g=rwx,o=rwx /libc-2.31.so
RUN chmod u=rwx,g=rwx,o=rwx ./ld-2.31.so
ENV LD_PRELOAD /libc-2.31.so

CMD ["./rtree"]
