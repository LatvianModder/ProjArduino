void write(int i)
{ server.write(i); }

void writeString(String s)
{
  write(s.length());
  for(int i = 0; i < s.length(); i++)
  write((int)s.charAt(i));
}

void writeShort(int i)
{ write((i >> 8) & 0xFF);
write((i >> 0) & 0xFF); }

int read(EthernetClient c)
{
  int i = c.read();
  while(i < 0) i = c.read();
  return i;
}

String readString(EthernetClient c)
{
  int i = read(c);
  String s = "";
  for(int j = 0; j < i; j++)
  s += (char)read(c);
  return s;
}

int readShort(EthernetClient c)
{
  int i1 = read(c); int i2 = read(c);
  int i =  (i1 << 8) + (i2 << 0);
  //if(i > 32767) i = (2*32768 - i); return i;
  return (short)i;
}

String buffer = "";

void print(String s)
{ buffer += s; Serial.print(s); }

void println(String s)
{
  print(s);
  Serial.print("[Console]: ");
  Serial.println(s);
  write(CONSOLE);
  writeString(buffer);
  buffer = "";
}

void print(int i)
{ String s = ""; s += i;
print(s); }

void println(int i)
{ String s = ""; s += i; 
println(s); }
