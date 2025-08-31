DEPEND_TARGETS += libcpp.build
ECHO_TARGETS += libcpp.echo
libcpp.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
libcpp.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libcpp/.make/super
