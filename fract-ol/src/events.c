/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:39:40 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:41:23 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void setup_hooks(void);

void handle_keypress(int keycode);

void handle_mouse(int button, int x, int y);

void handle_zoom(int direction, int x, int y);

void handle_close(void);
