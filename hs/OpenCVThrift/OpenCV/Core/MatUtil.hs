module OpenCVThrift.OpenCV.Core.MatUtil where

import Thrift.Protocol
import Thrift.Transport

import OpenCVThrift.OpenCV.Core

import qualified MatUtil_Client

{-data Client p t where-}
  {-Client :: (Protocol p, Transport t) => (p t, p t) -> Client p t-}

data Client p t = (Protocol p, Transport t) => Client (p t, p t)

class ToClient a p t | a -> p t where
  toClient :: a -> Client p t

instance ToClient (Client p t) p t where
  toClient = id  

{-bar :: Client p t -> CVType -> MatUnpacked -> IO Mat-}
{-bar (Client value) = MatUtil_Client.pack value-}

{-foo :: ToClient a p t => a -> CVType -> MatUnpacked -> IO Mat-}
{-foo client = bar $ toClient client -}
 {-where (Client value) = toClient client-}

pack :: ToClient a p t => a -> CVType -> MatUnpacked -> IO Mat
pack client = pack' $ toClient client
pack' (Client value) = MatUtil_Client.pack value

unpack :: ToClient a p t => a -> Mat -> IO MatUnpacked
unpack client = unpack' $ toClient client
unpack' (Client value) = MatUtil_Client.unpack value

{-pack client = MatUtil_Client.pack $ value $ toClient client-}

{-unpack :: ToClient a p t => a -> Mat -> IO MatUnpacked-}
{-unpack client = MatUtil_Client.unpack $ value $ toClient client-}


{-class (Protocol p, Transport t) => ToClient a p t | a -> p t where-}
  {-toClient :: a -> Client p t-}

{-instance (Protocol p, Transport t) => ToClient (Client p t) p t where-}
  {-toClient = id  -}

{-pack :: ToClient a p t => a -> CVType -> MatUnpacked -> IO Mat-}
{-pack client = MatUtil_Client.pack $ value $ toClient client-}

{-unpack :: ToClient a p t => a -> Mat -> IO MatUnpacked-}
{-unpack client = MatUtil_Client.unpack $ value $ toClient client-}

