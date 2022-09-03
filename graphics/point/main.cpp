#include <cstdio>

#include <windows.h>

using namespace std;

// COMPILE WITH A WINDOWS COMPILER
// SUCH AS VISUAL STUDIO C++ 2005
// OR LATER. PROGRAM TESTED ON
// WINDOWS 10, 8 and 7
int main()
{

  // the boot code for the above
  // assembly instructions
  // see the referenced pdf at the
  // end of this page
  BYTE mac_code[512] =
  {

    0xb4, 0x0e, 0xb0, 0x48, 0xcd, 0x10,
    0xb0, 0x65, 0xcd, 0x10, 0xb0, 0x6c,
    0xcd, 0x10, 0xb0, 0x6c, 0xcd, 0x10,
    0xb0, 0x6f, 0xcd, 0x10, 0xe9, 0xfd,
    0xff, 0x0
  };

  // boot signature
  mac_code[510] = { 0x55 };

  mac_code[511] = { 0xAA };

  // for safety we restrict to
  // USB less than 32 GB so that
  // accidental access to hdd
  // can be avoided
  const int MAX_USB_GB = 32;

  // get the drive letter
  // from the user
  printf("Drive letter of USB?: ");

  // scanf used for readability
  // and simplicity only.
  char path[] = "\\\\.\\?:";

  scanf_s("%c", path + 4, 1);

  // open the volume
  HANDLE hVol = CreateFileA(
  path,
  GENERIC_READ | GENERIC_WRITE,
  FILE_SHARE_READ | FILE_SHARE_WRITE,
  NULL,
  OPEN_EXISTING, 0,
  NULL);

  // if handle fails
  if (INVALID_HANDLE_VALUE == hVol)
  {

    printf("Check drive letter.");

    return -1;

  }

  // get the physicaldrive number
  // and the capacity of the disk
  VOLUME_DISK_EXTENTS vde = { 0 };

  DWORD dw;

  DeviceIoControl(
  hVol,
  IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS,
  NULL,
  0,
  (LPVOID)&vde,
  (DWORD)sizeof(VOLUME_DISK_EXTENTS),
  &dw, NULL
  );

  // check disk size
  if (
  vde.Extents[0].ExtentLength.QuadPart
  >

  LONGLONG(MAX_USB_GB * 1000000000LL)
  )
  {

    printf("USB too large\n");

    printf("Use < %d GB", MAX_USB_GB);

    CloseHandle(hVol);

    return -2;

  }

  // lock the volume
  DeviceIoControl(
  hVol,
  (DWORD)FSCTL_LOCK_VOLUME,
  NULL,
  NULL,
  NULL,
  NULL,
  &dw,
  NULL);

  // we should be able to write
  // to every sector from
  // start till the end
  DeviceIoControl(hVol,
  (DWORD)FSCTL_ALLOW_EXTENDED_DASD_IO,
  NULL,
  NULL,
  NULL,
  NULL,
  &dw,
  NULL);

  // open the disk now by using
  // the disk number
  // path format is \\.\PhysicalDriveN
  // so a buffer of 20 sufficient
  char diskPath[20] = { 0 };

  // use sprintf to construct
  // the path by appending
  // disk number to \\.\PhysicalDrive
  sprintf_s(diskPath,
  sizeof(diskPath),
  "\\\\.\\PhysicalDrive%d",
  vde.Extents[0].DiskNumber
  );

  // open a handle to the disk
  HANDLE hUsb = CreateFileA(
  diskPath,
  GENERIC_READ | GENERIC_WRITE,
  FILE_SHARE_READ | FILE_SHARE_WRITE,
  NULL,
  OPEN_EXISTING, 0,
  NULL);

  // if handle fails
  if (INVALID_HANDLE_VALUE == hUsb)
  {

    printf("Run as admn.");

    // unlock the volume
    DeviceIoControl(hVol,
    (DWORD)FSCTL_UNLOCK_VOLUME,
    NULL,
    NULL,
    NULL,
    NULL,
    &dw,
    NULL);

    CloseHandle(hVol);

    return -3;

  }

  // write the sector!
  WriteFile(hUsb,
  (void*)mac_code,
  sizeof(mac_code),
  &dw,
  NULL);

  // read back to verify now
  // set read pointer to start
  SetFilePointer(hUsb,
  0,
  NULL,
  FILE_BEGIN);

  // file pointer begins at 0
  // boot sector also starts at 0
  // so read now...
  ReadFile(hUsb,
  mac_code,
  sizeof(mac_code),
  &dw, NULL);

  printf("Boot sector: \n");

  for (int i = 0; i < 512; i++)
  {

    // create a row after every 16
    // columns so that display
    // looks good
    if (0 == i % 16)
    {

      printf("\n");

    }

    BYTE b = mac_code[i];

    printf("%02x ", b);

  }

  // unlock the volume
  DeviceIoControl(hVol,
  (DWORD)FSCTL_UNLOCK_VOLUME,
  NULL,
  NULL,
  NULL,
  NULL,
  &dw,
  NULL);

  // release handles
  CloseHandle(hVol);

  CloseHandle(hUsb);

  return 0;

}
