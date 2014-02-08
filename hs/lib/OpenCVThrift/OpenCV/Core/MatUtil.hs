module OpenCVThrift.OpenCV.Core.MatUtil where

import Thrift.Protocol
import Thrift.Transport

import OpenCVThrift.OpenCV.Core

import qualified MatUtil_Client

data Client p t = (Protocol p, Transport t) => Client { value :: (p t, p t) }

class (Protocol p, Transport t) => ToClient a p t | a -> p t where
  toClient :: a -> Client p t

instance (Protocol p, Transport t) => ToClient (Client p t) p t where
  toClient = id  

pack :: ToClient a p t => a -> CVType -> MatUnpacked -> IO Mat
pack client = MatUtil_Client.pack $ value $ toClient client

unpack :: ToClient a p t => a -> Mat -> IO MatUnpacked
unpack client = MatUtil_Client.unpack $ value $ toClient client

