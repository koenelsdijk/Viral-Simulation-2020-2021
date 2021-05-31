# Point at any base image that you find suitable to extend.


FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build

FROM httpd:2.4
WORKDIR /usr/local/apache2/htdocs/
COPY --from=builder /home/src/viralsim/build .