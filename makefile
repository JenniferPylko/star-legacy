all:
	$(MAKE) -C kzqcvm
	$(MAKE) -C SLEngine
	$(MAKE) -C SLGame
	$(MAKE) -C SLMapEditor

kzqcvm:
	$(MAKE) -C kzqcvm

engine: kzqcvm
	$(MAKE) -C SLEngine

game:
	$(MAKE) -C SLGame

editor:
	$(MAKE) -C SLMapEditor
