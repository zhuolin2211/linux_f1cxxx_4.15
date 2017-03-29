/*
 * Copyright (C) 2017 Icenowy Zheng <icenowy@aosc.io>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef _SUNXI_ENGINE_H_
#define _SUNXI_ENGINE_H_

struct sun4i_crtc;

struct sunxi_engine_ops {
	/* Commit the changes to the engine */
	void (*commit)(void *engine);
	/* Initialize layers (planes) for this engine */
	struct drm_plane **(*layers_init)(struct drm_device *drm,
					  struct sun4i_crtc *crtc);

	/*
	 * These are optional functions for the TV Encoder. Please check
	 * their presence before calling them.
	 *
	 * The first function applies the color space correction needed
	 * for outputing correct TV signal.
	 *
	 * The second function disabled the correction.
	 */
	void (*apply_color_correction)(void *engine);
	void (*disable_color_correction)(void *engine);
};

#endif /* _SUNXI_ENGINE_H_ */
