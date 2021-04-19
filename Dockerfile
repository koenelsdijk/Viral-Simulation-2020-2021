# Point at any base image that you find suitable to extend.
FROM emscripten/emsdk:2.0.15
# AS Base

WORKDIR /home/src/viralsim
  
COPY . .
 
# RUN make run-production