/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2004-2010  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

int set_nonblocking(int fd);

typedef void (*bt_callback_t) (sdp_list_t *recs, int err, gpointer user_data);
typedef void (*bt_destroy_t) (gpointer user_data);
typedef void (*bt_hci_result_t) (uint8_t status, gpointer user_data);

int bt_discover_services(const bdaddr_t *src, const bdaddr_t *dst,
		bt_callback_t cb, void *user_data, bt_destroy_t destroy);

int bt_search_service(const bdaddr_t *src, const bdaddr_t *dst,
			uuid_t *uuid, bt_callback_t cb, void *user_data,
			bt_destroy_t destroy);
int bt_cancel_discovery(const bdaddr_t *src, const bdaddr_t *dst);

gchar *bt_uuid2string(uuid_t *uuid);
uint16_t bt_name2class(const char *string);
char *bt_name2string(const char *string);
int bt_string2uuid(uuid_t *uuid, const char *string);
gchar *bt_list2string(GSList *list);
GSList *bt_string2list(const gchar *str);

int bt_acl_encrypt(const bdaddr_t *src, const bdaddr_t *dst,
			bt_hci_result_t cb, gpointer user_data);
