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
#include "crypto/Crypto.h"
#include "util/Base32.h"

#include <stdio.h>
#include <assert.h>

int main()
{
    uint8_t bytes[32];
    randombytes(bytes, 32);

    uint8_t base32[64];
    memset(base32, 0, 64);

    assert(Base32_encode(base32, 64, bytes, 32) == 52);

    //printf("base32 encoded: %s\n", base32);

    uint8_t bytes2[32];
    assert(Base32_decode(bytes2, 32, base32, 52) == 32);

    assert(memcmp(bytes, bytes2, 32) == 0);
}
