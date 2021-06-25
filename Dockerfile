# Point at any base image that you find suitable to extend.


FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build

FROM httpd:2.4 AS testserver
WORKDIR /usr/local/apache2/htdocs/
COPY --from=builder /home/src/viralsim/build .

FROM selenium/standalone-firefox:4.0.0-beta-4-20210608 AS tester

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS testbuilder
WORKDIR /home/src/viralsimtester
COPY --from=builder /home/src/viralsim/ViralSimulation.SeleniumTests ./ViralSimulation.SeleniumTests
COPY --from=builder /home/src/viralsim/build ../viralsim
#RUN rm -rf /home/src/viralsim/* 
RUN dotnet test; if [ $? -ne 0 ]; then rm -rf /home/src/viralsim; fi 
#RUN echo dotnet test

#testen

FROM testserver AS final
RUN rm -rf ./*
COPY --from=testbuilder /home/src/viralsim .

