module OpenCVLocalhost where

import qualified OpenCV
{-import qualified Internal.Util-}

{-import qualified OpenCV.Core.MatUtil-}
{-import OpenCV.Core.MatUtil-}

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import Data.Vector

{-data Service = MatUtil-}

{-getService :: String -> PortID -> IO Int-}
{-getService :: String -> PortID -> IO Client-}
getService name port = do
  putStrLn $ printf "Connecting to %s." name
  transport  <- hOpen ("localhost", port)
  let binProto = BinaryProtocol transport
  return (binProto, binProto)

openCVLocalhostProtocol = do
  matUtil <- getService "MatUtil" 9090
  return $ OpenCV.OpenCVProtocol matUtil

