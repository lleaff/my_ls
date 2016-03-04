void *noop(void *_)
{
    return (_);
}

void *noop2(void *_, void *__)
{
  noop(_);
  return (__);
}
