# Use the latest GCC image as the base
FROM gcc:latest

# Install CMake
RUN apt-get update && apt-get install -y cmake

# Copy the project files into the container
COPY . /usr/src/mytest

# Set the working directory
WORKDIR /usr/src/mytest

# Create a build directory
RUN mkdir build

# Change to the build directory
WORKDIR /usr/src/mytest/build

# Configure and build the project using CMake
RUN cmake .. && make

# Command to run the tests
CMD ["./MainApp"]
