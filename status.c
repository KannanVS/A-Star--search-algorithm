#include "status.h"

static char* unknownError = "Unknown error";

static char* msg[] = {
  "",
  "File open failed",
  "Access refused",
  "File close failed",
  "Memory allocation failed",
  "Wrong date",
  "Full structure",
  "Empty structure",
  "Value not found",
  "Value already exists",
  "Index out of bounds",
  "Unable to perform operation",
  
  "Unknown error"
};

char* message(status s) {
  return (s<0 || s >= ERRUNKNOWN) ? msg[ERRUNKNOWN] : msg[s];
}
