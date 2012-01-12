/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "crypto_hash_sha512.h"

#include <stdint.h>
#include <string.h>

void AddressCalc_addressForPublicKey(uint8_t addressOut[16], const uint8_t key[32])
{
    uint8_t hash[crypto_hash_sha512_BYTES];
    crypto_hash_sha512(hash, key, 32);
    crypto_hash_sha512(hash, hash, crypto_hash_sha512_BYTES);
    memcpy(addressOut, hash, 16);
}
