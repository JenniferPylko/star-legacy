kzqcvm:
	$(MAKE) -C kzqcvm

engine: kzqcvm
	$(MAKE) -C SLEngine

game:
	$(MAKE) -C SLGame

editor:
	$(MAKE) -C SLMapEditor

all: game
