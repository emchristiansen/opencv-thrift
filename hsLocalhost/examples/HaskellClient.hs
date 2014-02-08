--
-- Licensed to the Apache Software Foundation (ASF) under one
-- or more contributor license agreements. See the NOTICE file
-- distributed with this work for additional information
-- regarding copyright ownership. The ASF licenses this file
-- to you under the Apache License, Version 2.0 (the
-- "License"); you may not use this file except in compliance
-- with the License. You may obtain a copy of the License at
--
--   http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing,
-- software distributed under the License is distributed on an
-- "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
-- KIND, either express or implied. See the License for the
-- specific language governing permissions and limitations
-- under the License.
--

{-import qualified MatUtil_Client as MatUtil-}
{-import qualified Features2D_Client as Features2D-}
{-import Mat_Types-}

{-import OpenCV-}
{-import OpenCVTypes-}
import qualified OpenCV.Core.MatUtil
{-import OpenCV.Core.MatUtil-}

import qualified OpenCVLocalhost

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import Data.Vector

import OpenCV.Core.MatUtil
import OpenCV.Features2D.Features2D

cvType = CV_32FC1

matUnpacked = MatUnpacked 
  (Just 3) 
  (Just 2) 
  (Just 1) 
  (Just $ fromList [1, 2, 3, 4, 5, 6])

main = do
  putStrLn "Start"

  client <- OpenCVLocalhost.openCVClient

  packed <- pack client cvType matUnpacked

  putStrLn "Done"

