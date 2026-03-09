# Compiler and Flags
CXX = g++
CXXFLAGS = -I./graphics -Wall
LDFLAGS = -L./graphics -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

# Source and Output
SRC = dda_test.cpp
OBJ = $(SRC:.cpp=.o)
EXE = dda_test.exe

# WinBGIM Resource URLs
BGI_URL = https://raw.githubusercontent.com/Haseeb-ullah/winbgim/master/graphics.h
HDR_URL = https://raw.githubusercontent.com/Haseeb-ullah/winbgim/master/winbgim.h
LIB_URL = https://github.com/ahmedshakill/WinBGIm-64/releases/download/v1.0/libbgi.a

# Targets
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Setup target to download necessary files
setup:
	@echo "Downloading graphics.h..."
	@curl -sL $(BGI_URL) -o graphics/graphics.h
	@echo "Downloading winbgim.h..."
	@curl -sL $(HDR_URL) -o graphics/winbgim.h
	@echo "Downloading libbgi.a..."
	@curl -sL $(LIB_URL) -o graphics/libbgi.a
	@echo "Setup complete. You can now run 'make'."

clean:
	del /f $(OBJ) $(EXE)

.PHONY: all setup clean
