DEPEND_TARGETS += libmm.recursive
ECHO_TARGETS += libmm.echo
libmm.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodel/               >> /volumes/llama/home/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodel/.make >> /volumes/llama/home/alpine/libraries/libmm/.make/super
	cd /volumes/llama/home/alpine/libraries/libmm/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libmm/.make/super
libmm.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodel/               >> /volumes/llama/home/alpine/libraries/libmm/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodel/.make >> /volumes/llama/home/alpine/libraries/libmm/.make/super
	cd /volumes/llama/home/alpine/libraries/libmm/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libmm/.make/super
