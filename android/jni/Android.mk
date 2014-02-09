LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sfml-example

LOCAL_SRC_FILES := ../../main.cc, ../../src/EventHandler.cc, ../../src/Level.cc, ../../src/GameObjects/Towers/Tower.cc, ../../src/GameObjects/Enemies/Enemy.cc, ../../src/GameObjects/Projectiles/Projectile.cc, ../../src/GameObjects/VisualEffects/VisualEffect.cc, ../../src/AnimatedSprite.cc, ../../src/testfiles/AnimatedSpriteTest.cc, ../../src/GameHandler.cc, ../../src/MusicHandler.cc, ../../src/Loader/TextureLoader.cc, ../../src/Loader/Loader.cc, ../../src/Loader/SoundLoader.cc, ../../src/Loader/MusicLoader.cc, ../../src/Loader/FontLoader.cc

LOCAL_SHARED_LIBRARIES := sfml-system
LOCAL_SHARED_LIBRARIES += sfml-window
LOCAL_SHARED_LIBRARIES += sfml-graphics
LOCAL_SHARED_LIBRARIES += sfml-audio
LOCAL_SHARED_LIBRARIES += sfml-network
LOCAL_WHOLE_STATIC_LIBRARIES := sfml-main

include $(BUILD_SHARED_LIBRARY)

$(call import-module,sfml)
